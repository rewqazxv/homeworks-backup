package com.etc.mapper;

import com.etc.pojo.Comment;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;

public interface CommentMapper {
    @Select("select * from comment where reviewer_id=#{reviewerId}")
    List<Comment> selectByReviewerId(long reviewerId);

    @Select("select * from comment where id=#{id}")
    Comment selectById(long id);

    @Select("select * from comment where article_id=#{articleId}")
    List<Comment> selectByArticleId(long articleId);

    @Update({"update comment",
    "set review_passed=#{reviewPassed},review_date=now(),review_comment=#{reviewComment}",
    "where id=#{id}"})
    void update(Comment c);
}
