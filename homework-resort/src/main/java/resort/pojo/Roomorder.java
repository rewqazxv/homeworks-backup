package resort.pojo;


public class Roomorder {

  private long roomorderid;
  private String roomnum;
  private java.sql.Timestamp intime;
  private java.sql.Timestamp outtime;
  private long spa;
  private long mainuid;
  private double totalprice;
  private String comment;


  public long getRoomorderid() {
    return roomorderid;
  }

  public void setRoomorderid(long roomorderid) {
    this.roomorderid = roomorderid;
  }


  public String getRoomnum() {
    return roomnum;
  }

  public void setRoomnum(String roomnum) {
    this.roomnum = roomnum;
  }


  public java.sql.Timestamp getIntime() {
    return intime;
  }

  public void setIntime(java.sql.Timestamp intime) {
    this.intime = intime;
  }


  public java.sql.Timestamp getOuttime() {
    return outtime;
  }

  public void setOuttime(java.sql.Timestamp outtime) {
    this.outtime = outtime;
  }


  public long getSpa() {
    return spa;
  }

  public void setSpa(long spa) {
    this.spa = spa;
  }


  public long getMainuid() {
    return mainuid;
  }

  public void setMainuid(long mainuid) {
    this.mainuid = mainuid;
  }


  public double getTotalprice() {
    return totalprice;
  }

  public void setTotalprice(double totalprice) {
    this.totalprice = totalprice;
  }


  public String getComment() {
    return comment;
  }

  public void setComment(String comment) {
    this.comment = comment;
  }

}
