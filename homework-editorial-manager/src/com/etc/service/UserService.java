package com.etc.service;

import com.etc.mapper.UserMapper;
import com.etc.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserService {
    @Autowired
    private UserMapper userMapper;

    public User checkEmailAndPwd(String email, String password) {
        return userMapper.checkEmailAndPwd(email, password);
    }

    public User selectById(long id) {
        return userMapper.selectById(id);
    }
}
