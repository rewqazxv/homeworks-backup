package resort.dao;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import resort.pojo.Dishorder;

import java.util.List;

@Mapper
public interface DishOrderDao {
    @Select("select * from dishorder order by dishorderdate desc")
    List<Dishorder> getAllDishOrder();

    @Select("SELECT * from dishorder, roomorder where dishorder.roomorderid = roomorder.roomorderid and mainuid=#{uid} order by dishorderdate desc")
    List<Dishorder> getDishOrderByUid(long uid);

    @Insert("insert into dishorder(dishtype,roomorderid) values (#{dishtype},#{roomorderid})")
    void addDishOrder(Dishorder dishorder);

    @Update("update dishorder set done=true where dishorderid=#{id}")
    void setDishOrderDone(long id);

    @Select("select sum(price) from dish,dishorder where dish.dishtype=dishorder.dishtype and roomorderid=#{roomOrderId} order by dishorderdate desc")
    Double countByRoomOrderId(long roomOrderId);
}
