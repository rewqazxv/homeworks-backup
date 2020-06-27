package com.etc.service;

import com.etc.mapper.ArticleMapper;
import com.etc.mapper.CommentMapper;
import com.etc.mapper.UserMapper;
import com.etc.pojo.Article;
import com.etc.pojo.Comment;
import com.etc.pojo.User;
import com.etc.util.Tuple3;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class CommentService {
    @Autowired
    private CommentMapper commentMapper;
    @Autowired
    private ArticleMapper articleMapper;
    @Autowired
    private UserMapper userMapper;

    public List<Tuple3<Comment, Article, User>> selectByReviewerId(long id) {
        List<Comment> comments = commentMapper.selectByReviewerId(id);
        List<Tuple3<Comment, Article, User>> res = new ArrayList<>();
        for (var i : comments) {
            res.add(new Tuple3<Comment, Article, User>(
                    i,
                    articleMapper.selectById(i.getArticleId()),
                    userMapper.selectById(articleMapper.selectById(i.getArticleId()).getAuthorId())
            ));
        }
        return res;
    }

    public Comment selectById(int id) {
        return commentMapper.selectById(id);
    }

    public List<Comment> selectByArticleId(long articleId) {
        return commentMapper.selectByArticleId(articleId);
    }

    public void update(Comment c) {
        commentMapper.update(c);
    }
}