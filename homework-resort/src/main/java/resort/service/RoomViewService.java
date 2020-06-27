package resort.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.stereotype.Service;
import resort.dao.RoomDao;
import resort.dao.RoomOrderDao;
import resort.pojo.Room;
import resort.pojo.Roomorder;

import java.util.List;

@Service
public class RoomViewService {
    @Autowired
    private RoomDao roomDao;
    @Autowired
    private RoomOrderDao roomOrderDao;

    @Secured("ROLE_ADMIN")
    public List<Room> allRoom() {
        return roomDao.getAllRoom();
    }

    @Secured("ROLE_ADMIN")
    public List<Roomorder> allRoomOrder() {
        return roomOrderDao.getAllRoomOrder();
    }

    @Secured("ROLE_ADMIN")
    public List<Roomorder> activeRoomOrder() {
        return roomOrderDao.getActiveRoomOrder();
    }

    public List<Roomorder> roomOrderByUid(long uid) {
        return roomOrderDao.getRoomOrderAllByUid(uid);
    }

    public List<Roomorder> roomOrderActiveByUid(long uid) {
        return roomOrderDao.getActiveRoomOrderByUid(uid);
    }

    public List<Room> roomByUid(long uid) {
        return roomDao.getRoomByUid(uid);
    }

    public List<Room> emptyRoom() {
        return roomDao.getEmptyRoom();
    }
}
