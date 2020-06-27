package resort.security;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.AuthorityUtils;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;
import resort.dao.PasswordDao;
import resort.dao.UserDao;
import resort.pojo.Password;
import resort.pojo.User;

import java.util.Collection;

@Service("userDetailsService")
public class LocalUserDetailsService implements UserDetailsService {
    @Autowired
    private UserDao userDao;
    @Autowired
    private PasswordDao passwordDao;

    @Override
    public UserDetails loadUserByUsername(String s) throws UsernameNotFoundException {
        User user = userDao.getUserBytel(s);
        if (user == null)
            throw new UsernameNotFoundException("");
        Password password = passwordDao.getPasswordByUid(user.getUid());
        return new org.springframework.security.core.userdetails.User(
                String.valueOf(user.getUid()),
                "{noop}" + password.getPassword(),
                createAuthorities(password)
        );
    }

    private Collection<? extends GrantedAuthority> createAuthorities(Password password) {
        if (password.getIsadmin() == 1)
            return AuthorityUtils.createAuthorityList("ROLE_ADMIN", "ROLE_USER");
        return AuthorityUtils.createAuthorityList("ROLE_USER");
    }
}