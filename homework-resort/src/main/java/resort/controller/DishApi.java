package resort.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.web.bind.annotation.*;
import resort.pojo.Dish;
import resort.service.DishService;

import java.util.List;
import java.util.Map;

@RestController
public class DishApi {
    @Autowired
    private DishService dishService;

    @GetMapping("/user/dish")
    public List<Dish> allDish() {
        return dishService.allDish();
    }

    @PostMapping("/admin/dish")
    @Secured("ROLE_ADMIN")
    public void addDish(@RequestBody Map<String, Object> body) {
        String type = (String) body.get("type");
        double price = Double.parseDouble((String) body.get("price"));
        dishService.addDish(type, price);
    }

    @DeleteMapping("/admin/dish/{type}")
    @Secured("ROLE_ADMIN")
    public void delDish(@PathVariable String type) {
        dishService.delDish(type);
    }
}
