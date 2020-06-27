package com.etc.pojo;


public class Article {

  private long id;
  private long authorId;
  private String title;
  private String category;
  private String keywords;
  private java.sql.Timestamp submitDate;
  private java.sql.Timestamp updateDate;
  private long paidReviewFee;
  private long paidPageCharges;
  private long receivedRemuneration;
  private long passed;
  private String content;


  public long getId() {
    return id;
  }

  public void setId(long id) {
    this.id = id;
  }


  public long getAuthorId() {
    return authorId;
  }

  public void setAuthorId(long authorId) {
    this.authorId = authorId;
  }


  public String getTitle() {
    return title;
  }

  public void setTitle(String title) {
    this.title = title;
  }


  public String getCategory() {
    return category;
  }

  public void setCategory(String category) {
    this.category = category;
  }


  public String getKeywords() {
    return keywords;
  }

  public void setKeywords(String keywords) {
    this.keywords = keywords;
  }


  public java.sql.Timestamp getSubmitDate() {
    return submitDate;
  }

  public void setSubmitDate(java.sql.Timestamp submitDate) {
    this.submitDate = submitDate;
  }


  public java.sql.Timestamp getUpdateDate() {
    return updateDate;
  }

  public void setUpdateDate(java.sql.Timestamp updateDate) {
    this.updateDate = updateDate;
  }


  public long getPaidReviewFee() {
    return paidReviewFee;
  }

  public void setPaidReviewFee(long paidReviewFee) {
    this.paidReviewFee = paidReviewFee;
  }


  public long getPaidPageCharges() {
    return paidPageCharges;
  }

  public void setPaidPageCharges(long paidPageCharges) {
    this.paidPageCharges = paidPageCharges;
  }


  public long getReceivedRemuneration() {
    return receivedRemuneration;
  }

  public void setReceivedRemuneration(long receivedRemuneration) {
    this.receivedRemuneration = receivedRemuneration;
  }


  public long getPassed() {
    return passed;
  }

  public void setPassed(long passed) {
    this.passed = passed;
  }


  public String getContent() {
    return content;
  }

  public void setContent(String content) {
    this.content = content;
  }

}
