package resort.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import resort.pojo.User;
import resort.service.UserService;

import java.util.List;

@RestController
public class UserApi {
    @Autowired
    private UserService userService;

    @GetMapping("/admin/user")
    @Secured("ROLE_ADMIN")
    public List<User> getAllUser() {
        return userService.getAllUser();
    }

    @GetMapping("/me")
    public User getMineInfo() {
        return userService.myInfo();
    }

    @GetMapping("/me/role")
    public String getRole() {
        return userService.iAmAdmin() ? "ADMIN" : "USER";
    }
}
