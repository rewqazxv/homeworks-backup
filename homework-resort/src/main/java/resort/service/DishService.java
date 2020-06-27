package resort.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import resort.dao.DishDao;
import resort.dao.DishOrderDao;
import resort.dao.RoomDao;
import resort.dao.RoomOrderDao;
import resort.pojo.Dish;
import resort.pojo.Dishorder;
import resort.pojo.Room;

import java.util.List;

@Service
public class DishService {
    @Autowired
    private DishDao dishDao;
    @Autowired
    private DishOrderDao dishOrderDao;
    @Autowired
    private RoomOrderDao roomOrderDao;
    @Autowired
    private RoomDao roomDao;

    @Secured("ROLE_ADMIN")
    public void addDish(String dishtype, double price) {
        Dish dish = new Dish();
        dish.setDishtype(dishtype);
        dish.setPrice(price);
        dishDao.addDish(dish);
    }

    @Secured("ROLE_ADMIN")
    public void delDish(String dishtype) {
        dishDao.delDish(dishtype);
    }

    public List<Dish> allDish() {
        return dishDao.getAllDish();
    }

    @Transactional
    public void addDishOrder(String roomnum, String dishtype) throws Exception {
        if (!roomDao.getRoomByRoomNum(roomnum).getStatus().equals("occupied"))
            throw new Exception("status error");
        long id = roomOrderDao.getActiveRoomOrderByRoomNum(roomnum).getRoomorderid();
        Dishorder dishorder = new Dishorder();
        dishorder.setRoomorderid(id);
        dishorder.setDishtype(dishtype);
        dishOrderDao.addDishOrder(dishorder);
    }

    @Secured("ROLE_ADMIN")
    public List<Dishorder> AllDishOrder() {
        return dishOrderDao.getAllDishOrder();
    }

    public List<Dishorder> UserDishOrder(long uid) {
        return dishOrderDao.getDishOrderByUid(uid);
    }

    @Secured("ROLE_ADMIN")
    public void dishOrderDone(long dishorderid) {
        dishOrderDao.setDishOrderDone(dishorderid);
    }
}
