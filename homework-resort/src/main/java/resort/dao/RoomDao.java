package resort.dao;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import resort.pojo.Room;

import java.util.List;

@Mapper
public interface RoomDao {
    @Select("select * from room")
    List<Room> getAllRoom();

    @Select("select * from room where status='empty'")
    List<Room> getEmptyRoom();

    @Select("select * from room where roomnum=#{roomnum}")
    Room getRoomByRoomNum(String roomnum);

    @Select("select * from room,roomorder where room.roomnum=roomorder.roomnum and outtime is null and mainuid=#{uid}")
    List<Room> getRoomByUid(long uid);

    @Update("update room set status='occupied' where roomnum=#{roomnum}")
    void setRoomOccupied(String roomnum);

    @Update("update room set status='dirty',username=null where roomnum=#{roomnum}")
    void setRoomDirty(String roomnum);

    @Update("update room set status='empty',username=null where roomnum=#{roomnum}")
    void setRoomEmpty(String roomnum);

    @Update("update room set status='booked',username=#{username} where roomnum=#{roomnum}")
    void setRoomBooked(String roomnum, String username);
}
