package resort.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;
import resort.dao.PasswordDao;
import resort.dao.RoomOrderDao;
import resort.dao.UserDao;
import resort.pojo.Roomorder;
import resort.pojo.User;

import javax.annotation.PostConstruct;
import java.util.List;

@Service
public class UserService {
    @Autowired
    private UserDao userDao;
    @Autowired
    private PasswordDao passwordDao;
    @Autowired
    private RoomOrderDao roomOrderDao;

    @Secured("ROLE_ADMIN")
    public List<User> getAllUser() {
        return userDao.getAllUser();
    }

    public User myInfo() {
        long uid = Long.parseLong(SecurityContextHolder.getContext().getAuthentication().getName());
        return userDao.getUserByUid(uid);
    }

    public long myUid() {
        return myInfo().getUid();
    }

    public boolean iAmAdmin() {
        return passwordDao.getPasswordByUid(myUid()).getIsadmin()==1;
    }

    public boolean iHaveRoom(String roomNum) {
        List<Roomorder> myRoomOrderActive = roomOrderDao.getActiveRoomOrderByUid(myUid());
        for (var i : myRoomOrderActive)
            if (i.getRoomnum().equals(roomNum)) return true;
        return false;
    }
}
