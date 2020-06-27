package resort.pojo;


public class Room {

  private String roomnum;
  private String roomtype;
  private double price;
  private String status;
  private double spaprice;
  private String username;


  public String getRoomnum() {
    return roomnum;
  }

  public void setRoomnum(String roomnum) {
    this.roomnum = roomnum;
  }


  public String getRoomtype() {
    return roomtype;
  }

  public void setRoomtype(String roomtype) {
    this.roomtype = roomtype;
  }


  public double getPrice() {
    return price;
  }

  public void setPrice(double price) {
    this.price = price;
  }


  public String getStatus() {
    return status;
  }

  public void setStatus(String status) {
    this.status = status;
  }


  public double getSpaprice() {
    return spaprice;
  }

  public void setSpaprice(double spaprice) {
    this.spaprice = spaprice;
  }


  public String getUsername() {
    return username;
  }

  public void setUsername(String username) {
    this.username = username;
  }

}
