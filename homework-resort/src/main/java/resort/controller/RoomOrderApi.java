package resort.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;
import resort.pojo.Roomorder;
import resort.service.RoomActionService;
import resort.service.RoomViewService;
import resort.service.UserService;

import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Map;
import java.util.Date;

@RestController
public class RoomOrderApi {
    @Autowired
    private RoomActionService roomActionService;
    @Autowired
    private RoomViewService roomViewService;
    @Autowired
    private UserService userService;

    @GetMapping("/admin/roomorder")
    @Secured("ROLE_ADMIN")
    public List<Roomorder> allRoomOrder() {
        return roomViewService.allRoomOrder();
    }

    @GetMapping("/admin/roomorder/active")
    @Secured("ROLE_ADMIN")
    public List<Roomorder> activeRoomOrder() {
        return roomViewService.activeRoomOrder();
    }

    @GetMapping("/me/roomorder")
    public List<Roomorder> myRoomOrder() {
        return roomViewService.roomOrderByUid(userService.myUid());
    }

    @GetMapping("/me/roomorder/active")
    public List<Roomorder> myActiveRoomOrder() {
        return roomViewService.roomOrderActiveByUid(userService.myUid());
    }

    @PostMapping("/me/roomorder")
    public void addRoomOrder(@RequestBody Map<String, Object> body) throws Exception {
        long uid = userService.myUid();
        boolean spa = (boolean) body.get("spa");
        String roomnum = (String) body.get("roomnum");
        roomActionService.book(roomnum, spa, uid);
    }
}
