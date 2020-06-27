package resort.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.web.bind.annotation.*;
import resort.pojo.Dishorder;
import resort.service.DishService;
import resort.service.UserService;

import java.util.List;
import java.util.Map;

@RestController
public class DishOrderApi {
    @Autowired
    private DishService dishService;
    @Autowired
    private UserService userService;

    @GetMapping("/me/dishorder")
    public List<Dishorder> myDishOrder() {
        return dishService.UserDishOrder(userService.myUid());
    }

    @PostMapping("/user/dishorder")
    public void addDishOrder(@RequestBody Map<String, Object> body) throws Exception {
        String dish = (String) body.get("dish");
        String room = (String) body.get("room");
        if (!userService.iHaveRoom(room) && !userService.iAmAdmin()) throw new Exception("no permission");
        dishService.addDishOrder(room, dish);
    }

    @GetMapping("/admin/dishorder")
    @Secured("ROLE_ADMIN")
    public List<Dishorder> allDishOrder() {
        return dishService.AllDishOrder();
    }

    @PutMapping("/admin/dishorder/{id}")
    @Secured("ROLE_ADMIN")
    public void dishOrderDone(@PathVariable long id) {
        dishService.dishOrderDone(id);
    }
}
