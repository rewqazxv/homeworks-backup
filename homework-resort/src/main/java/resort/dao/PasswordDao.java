package resort.dao;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import resort.pojo.Password;

@Mapper
public interface PasswordDao {
    @Select("select * from password where uid=#{uid}")
    Password getPasswordByUid(long uid);
}
