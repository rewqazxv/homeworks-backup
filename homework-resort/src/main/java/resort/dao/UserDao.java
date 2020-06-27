package resort.dao;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import resort.pojo.User;

import java.util.List;

@Mapper
public interface UserDao {
    @Select("select * from user where tel=#{tel}")
    User getUserBytel(String tel);

    @Select("select * from user where uid=#{uid}")
    User getUserByUid(long uid);

    @Select("select * from user")
    List<User> getAllUser();
}
