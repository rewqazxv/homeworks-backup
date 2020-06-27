package resort.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import resort.dao.DishOrderDao;
import resort.dao.RoomDao;
import resort.dao.RoomOrderDao;
import resort.dao.UserDao;
import resort.pojo.Room;
import resort.pojo.Roomorder;
import resort.pojo.User;

@Service
public class RoomActionService {
    @Autowired
    private RoomDao roomDao;
    @Autowired
    private RoomOrderDao roomOrderDao;
    @Autowired
    private DishOrderDao dishOrderDao;
    @Autowired
    private UserDao userDao;

    @Transactional
    public void book(String roomnum, boolean spa, long uid) {
        roomOrderDao.addRoomOrder(roomnum, spa, uid);
        roomDao.setRoomBooked(roomnum, userDao.getUserByUid(uid).getName());
    }

    @Transactional
    @Secured("ROLE_ADMIN")
    public void checkin(String roomnum) throws Exception {
        Room room = roomDao.getRoomByRoomNum(roomnum);
        if (!room.getStatus().equals("booked")) throw new Exception("status error");
        roomDao.setRoomOccupied(roomnum);
    }

    @Transactional
    public double checkout(String roomnum, String comment) throws Exception {
        Room room = roomDao.getRoomByRoomNum(roomnum);
        if (!room.getStatus().equals("occupied")) throw new Exception("status error");
        roomDao.setRoomDirty(roomnum);

        Roomorder roomorder = roomOrderDao.getActiveRoomOrderByRoomNum(roomnum);
        double bill = room.getPrice();
        if (roomorder.getSpa() == 1) bill += room.getSpaprice();
        Double dishBill = dishOrderDao.countByRoomOrderId(roomorder.getRoomorderid());
        if (dishBill == null) dishBill = 0.0;
        bill += dishBill;
        roomOrderDao.checkoutRoomOrder(roomnum, bill, comment);

        return bill;
    }

    @Transactional
    @Secured("ROLE_ADMIN")
    public void clean(String roomnum) throws Exception {
        Room room = roomDao.getRoomByRoomNum(roomnum);
        if (!room.getStatus().equals("dirty")) throw new Exception("status error");
        roomDao.setRoomEmpty(roomnum);
    }

    @Transactional
    public void changeRoomBeforeCheckin(String oldRoomNum, String newRoomNum) throws Exception {
        Roomorder roomorder = roomOrderDao.getActiveRoomOrderByRoomNum(oldRoomNum);
        if (roomorder == null) throw new Exception("no such room order");
        Room newRoom = roomDao.getRoomByRoomNum(newRoomNum);
        Room oldRoom = roomDao.getRoomByRoomNum(oldRoomNum);
        if (!oldRoom.getStatus().equals("booked") || !newRoom.getStatus().equals("empty"))
            throw new Exception("status error");
        roomDao.setRoomEmpty(oldRoomNum);
        roomDao.setRoomBooked(newRoomNum, userDao.getUserByUid(roomorder.getMainuid()).getName());
        roomOrderDao.changeRoom(oldRoomNum, newRoomNum);
    }
}
