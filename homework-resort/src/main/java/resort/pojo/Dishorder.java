package resort.pojo;


public class Dishorder {

  private long dishorderid;
  private String dishtype;
  private java.sql.Timestamp dishorderdate;
  private long roomorderid;
  private long done;


  public long getDishorderid() {
    return dishorderid;
  }

  public void setDishorderid(long dishorderid) {
    this.dishorderid = dishorderid;
  }


  public String getDishtype() {
    return dishtype;
  }

  public void setDishtype(String dishtype) {
    this.dishtype = dishtype;
  }


  public java.sql.Timestamp getDishorderdate() {
    return dishorderdate;
  }

  public void setDishorderdate(java.sql.Timestamp dishorderdate) {
    this.dishorderdate = dishorderdate;
  }


  public long getRoomorderid() {
    return roomorderid;
  }

  public void setRoomorderid(long roomorderid) {
    this.roomorderid = roomorderid;
  }


  public long getDone() {
    return done;
  }

  public void setDone(long done) {
    this.done = done;
  }

}
