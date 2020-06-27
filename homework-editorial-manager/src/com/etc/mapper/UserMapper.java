package com.etc.mapper;

import com.etc.pojo.User;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

public interface UserMapper {
    @Select("select * from user where email = #{email} and password = #{password}")
    User checkEmailAndPwd(@Param("email") String email, @Param("password") String password);

    @Select("select * from user where id = #{id}")
    User selectById(@Param("id") long id);
}
