package com.etc.web;

import com.etc.pojo.Article;
import com.etc.pojo.Comment;
import com.etc.pojo.User;
import com.etc.service.ArticleService;
import com.etc.service.CommentService;
import com.etc.service.UserService;
import com.etc.util.Tuple3;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import javax.servlet.http.HttpSession;
import java.util.List;

@Controller
@RequestMapping(value = "/comment")
public class CommentController {
    @Autowired
    private CommentService commentService;
    @Autowired
    private ArticleService articleService;
    @Autowired
    private UserService userService;

    @RequestMapping("/todoController")
    public String todoController(HttpSession session, Model model) {
        User user = (User) session.getAttribute("user");
        List<Tuple3<Comment, Article, User>> tuple3List = commentService.selectByReviewerId(user.getId());
        model.addAttribute("tuple3List", tuple3List);
        return "todoReview";
    }

    @RequestMapping("/reviewController/{reviewId}")
    public String reviewController(HttpSession session, Model model,
                                   @PathVariable int reviewId) {
        Comment comment = commentService.selectById(reviewId);
        Article article = articleService.selectById(comment.getArticleId());
        User author = userService.selectById(article.getAuthorId());
        model.addAttribute("review", comment);
        model.addAttribute("article", article);
        model.addAttribute("author",author);
        return "review";
    }

    @RequestMapping("/submitController/{reviewId}")
    public String submit(@PathVariable int reviewId,
                         HttpSession session, Model model,
                         @RequestParam("content") String content,
                         @RequestParam(value = "mypassed", required = false) String mypassed) {
        Comment comment = commentService.selectById(reviewId);
        if (mypassed != null)
            comment.setReviewPassed(1);
        comment.setReviewComment(content);
        commentService.update(comment);
        model.addAttribute("submitSuccess", true);
        return "redirect:/comment/todoController";
    }
}
