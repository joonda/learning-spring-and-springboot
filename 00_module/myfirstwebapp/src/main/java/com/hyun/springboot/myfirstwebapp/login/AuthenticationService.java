package com.hyun.springboot.myfirstwebapp.login;

import org.springframework.stereotype.Service;

@Service
public class AuthenticationService {
    public boolean authenticate(String username, String password) {
        
        boolean isValidUserName =  username.equals("Hyun");
        boolean isValidPassword = password.equals("dummy");

        return isValidUserName && isValidPassword;
    }
}
