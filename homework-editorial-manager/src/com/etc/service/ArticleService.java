package com.etc.service;

import com.etc.mapper.ArticleMapper;
import com.etc.pojo.Article;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ArticleService {
    @Autowired
    private ArticleMapper articleMapper;

    public void insert(Article n) {
        articleMapper.insert(n);
    }

    public List<Article> selectByUserId(long userId) {
        return articleMapper.selectByUserId(userId);
    }

    public Article selectById(long id) {
        return articleMapper.selectById(id);
    }

    public void update(Article article) {
        articleMapper.update(article);
    }

    public List<Article> selectAll() {
        return articleMapper.selectAll();
    }
}
