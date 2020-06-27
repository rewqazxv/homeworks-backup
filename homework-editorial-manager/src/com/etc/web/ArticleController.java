package com.etc.web;

import com.etc.pojo.Article;
import com.etc.pojo.Comment;
import com.etc.pojo.User;
import com.etc.service.ArticleService;
import com.etc.service.CommentService;
import com.etc.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import javax.servlet.http.HttpSession;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Controller
@RequestMapping(value = "/article")
public class ArticleController {
    @Autowired
    private ArticleService articleService;
    @Autowired
    private CommentService commentService;
    @Autowired
    private UserService userService;

    @RequestMapping(value = "/submitController")
    public String submitController() {
        return "submit";
    }

    @RequestMapping(value = "/submitArticle")
    public String submitArticle(@RequestParam("title") String title,
                                @RequestParam("content") String content,
                                Model model, HttpSession session) {
        Article article = new Article();
        User user = (User) session.getAttribute("user");
        article.setAuthorId(user.getId());
        article.setTitle(title);
        article.setContent(content);
        articleService.insert(article);
        model.addAttribute("submitSuccess", true);
        return "submit";
    }

    @RequestMapping(value = "/updateArticle/{articleId}")
    public String updateArticle(@RequestParam("title") String title,
                                @RequestParam("content") String content,
                                @PathVariable Integer articleId,
                                Model model, HttpSession session) {
        Article article = articleService.selectById(articleId);
        article.setTitle(title);
        article.setContent(content);
        articleService.update(article);
        model.addAttribute("submitSuccess", true);
        return "submit";
    }

    @RequestMapping(value = "/userAllArticlesController")
    public String userAllArticle(HttpSession session, Model model) {
        User user = (User) session.getAttribute("user");
        List<Article> articles = articleService.selectByUserId(user.getId());
        model.addAttribute("articles", articles);
        return "articles";
    }

    @RequestMapping("/articleDetailController/{articleId}")
    public String articleDetailController(HttpSession session,
                                          Model model, @PathVariable Integer articleId) {
        Article article = articleService.selectById(articleId);
        List<Comment> reviews = commentService.selectByArticleId(articleId);
        model.addAttribute("editArticle", article);
        model.addAttribute("reviews", reviews);
        User user = (User) session.getAttribute("user");
        if (user.getIsAdmin() == 1) {
            Map<Long, User> idUserMap = new HashMap<>();
            for (var i : reviews) {
                idUserMap.put(i.getReviewerId(), userService.selectById(i.getReviewerId()));
            }
            idUserMap.put(article.getAuthorId(),userService.selectById(article.getAuthorId()));
            model.addAttribute("idUserMap", idUserMap);
        }
        return "submit";
    }

    @RequestMapping("/allController")
    public String allController(Model model) {
        List<Article> articles = articleService.selectAll();
        model.addAttribute("articles", articles);
        Map<Long, User> idUserMap = new HashMap<>();
        for (var i : articles) {
            idUserMap.put(i.getAuthorId(), userService.selectById(i.getAuthorId()));
        }
        model.addAttribute("idUserMap", idUserMap);
        return "articles";
    }
}
