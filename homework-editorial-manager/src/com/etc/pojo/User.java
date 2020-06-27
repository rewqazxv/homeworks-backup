package com.etc.pojo;


public class User {

  private long id;
  private String email;
  private String password;
  private String name;
  private String unit;
  private long isReviewer;
  private long isAdmin;


  public long getId() {
    return id;
  }

  public void setId(long id) {
    this.id = id;
  }


  public String getEmail() {
    return email;
  }

  public void setEmail(String email) {
    this.email = email;
  }


  public String getPassword() {
    return password;
  }

  public void setPassword(String password) {
    this.password = password;
  }


  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }


  public String getUnit() {
    return unit;
  }

  public void setUnit(String unit) {
    this.unit = unit;
  }


  public long getIsReviewer() {
    return isReviewer;
  }

  public void setIsReviewer(long isReviewer) {
    this.isReviewer = isReviewer;
  }


  public long getIsAdmin() {
    return isAdmin;
  }

  public void setIsAdmin(long isAdmin) {
    this.isAdmin = isAdmin;
  }

}
