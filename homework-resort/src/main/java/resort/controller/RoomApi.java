package resort.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.web.bind.annotation.*;
import resort.pojo.Room;
import resort.service.RoomActionService;
import resort.service.RoomViewService;
import resort.service.UserService;

import java.util.List;
import java.util.Map;

@RestController
public class RoomApi {
    @Autowired
    private RoomViewService roomViewService;
    @Autowired
    private RoomActionService roomActionService;
    @Autowired
    private UserService userService;

    @GetMapping("/user/room/available")
    public List<Room> availableRoom() {
        return roomViewService.emptyRoom();
    }

    @PostMapping("/user/room/{roomnum}")
    public double checkout(@PathVariable String roomnum, @RequestBody Map<String, Object> body) throws Exception {
        if (!userService.iHaveRoom(roomnum) && !userService.iAmAdmin()) throw new Exception("no permission");
        String comment = (String) body.get("comment");
        return roomActionService.checkout(roomnum, comment);
    }

    @PutMapping("/user/room/{roomnum}")
    public void changeRoom(@PathVariable String roomnum, @RequestBody Map<String, Object> body) throws Exception {
        if (!userService.iHaveRoom(roomnum) && !userService.iAmAdmin()) throw new Exception("no permission");
        String newRoomNum = (String) body.get("newRoomNum");
        roomActionService.changeRoomBeforeCheckin(roomnum, newRoomNum);
    }

    @GetMapping("/me/room")
    public List<Room> myRoom() {
        return roomViewService.roomByUid(userService.myUid());
    }

    @GetMapping("/admin/room")
    @Secured("ROLE_ADMIN")
    public List<Room> allRoom() {
        return roomViewService.allRoom();
    }

    @PutMapping("/admin/room/{roomnum}")
    @Secured("ROLE_ADMIN")
    public void checkinOrCleanRoom(@PathVariable String roomnum, @RequestBody Map<String, Object> body) throws Exception {
        if (body.get("action").equals("clean"))
            roomActionService.clean(roomnum);
        else if (body.get("action").equals("checkin"))
            roomActionService.checkin(roomnum);
    }
}
