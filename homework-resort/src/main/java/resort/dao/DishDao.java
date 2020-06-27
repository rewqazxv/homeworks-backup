package resort.dao;

import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import resort.pojo.Dish;

import java.util.List;

@Mapper
public interface DishDao {
    @Select("select * from dish")
    List<Dish> getAllDish();

    @Insert("insert into dish(dishtype,price) values (#{dishtype},#{price})")
    long addDish(Dish dish);

    @Delete("delete from dish where dishtype=#{dishtype}")
    void delDish(String dishtype);
}
