package com.etc.mapper;

import com.etc.pojo.Article;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;

public interface ArticleMapper {
    @Select("select * from article where author_id=#{userId}")
    List<Article> selectByUserId(long userId);

    @Select("select * from article where id=#{id}")
    Article selectById(long id);

    @Select("select * from article")
    List<Article> selectAll();

    @Update({"update article",
            "set title=#{title},category=#{category},keywords=#{keywords},update_date=now(),content=#{content}",
            "where id=#{id}"})
    void update(Article article);

    @Insert({"insert into article(author_id,title,category,keywords,content)",
            "values (#{authorId},#{title},#{category},#{keywords},#{content})"})
    void insert(Article article);
}
