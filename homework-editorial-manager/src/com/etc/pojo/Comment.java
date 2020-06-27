package com.etc.pojo;


public class Comment {

  private long id;
  private long articleId;
  private long reviewerId;
  private long reviewPassed;
  private java.sql.Timestamp reviewDate;
  private String reviewComment;


  public long getId() {
    return id;
  }

  public void setId(long id) {
    this.id = id;
  }


  public long getArticleId() {
    return articleId;
  }

  public void setArticleId(long articleId) {
    this.articleId = articleId;
  }


  public long getReviewerId() {
    return reviewerId;
  }

  public void setReviewerId(long reviewerId) {
    this.reviewerId = reviewerId;
  }


  public long getReviewPassed() {
    return reviewPassed;
  }

  public void setReviewPassed(long reviewPassed) {
    this.reviewPassed = reviewPassed;
  }


  public java.sql.Timestamp getReviewDate() {
    return reviewDate;
  }

  public void setReviewDate(java.sql.Timestamp reviewDate) {
    this.reviewDate = reviewDate;
  }


  public String getReviewComment() {
    return reviewComment;
  }

  public void setReviewComment(String reviewComment) {
    this.reviewComment = reviewComment;
  }

}
