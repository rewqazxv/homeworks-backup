package resort.dao;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import resort.pojo.Roomorder;

import java.sql.Timestamp;
import java.util.List;

@Mapper
public interface RoomOrderDao {
    @Select("select * from roomorder order by intime desc")
    List<Roomorder> getAllRoomOrder();

    @Select("select * from roomorder where outtime is null order by intime desc")
    List<Roomorder> getActiveRoomOrder();

    @Select("select * from roomorder where mainuid=#{uid} order by intime desc")
    List<Roomorder> getRoomOrderAllByUid(long uid);

    @Select("select * from roomorder where outtime is NULL and mainuid=#{uid} order by intime desc")
    List<Roomorder> getActiveRoomOrderByUid(long uid);

    @Select("select * from roomorder where outtime is null and roomnum=#{roomnum} order by intime desc")
    Roomorder getActiveRoomOrderByRoomNum(String roomnum);

    @Update("update roomorder set outtime=CURRENT_TIMESTAMP,totalprice=#{totalprice},comment=#{comment} where outtime is null and roomnum=#{roomnum}")
    void checkoutRoomOrder(String roomnum, double totalprice, String comment);

    @Update("update roomorder set roomnum=#{newRoomNum} where outtime is null and roomnum=#{oldRoomNum}")
    void changeRoom(String oldRoomNum, String newRoomNum);

    @Insert("insert into roomorder(roomnum,spa,mainuid) values (#{roomnum},#{spa},#{uid})")
    void addRoomOrder(String roomnum, boolean spa, long uid);
}
