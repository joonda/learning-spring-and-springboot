package com.hyun.springboot.learn_spring_boot;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Arrays;
import java.util.List;

@RestController
public class CourseController {

    // /courses를 노출
    @RequestMapping("/courses")
    public List<Course> retrieveAllCourses() {
        return Arrays.asList(
                new Course(1, "Learn AWS", "Hyun"),
                new Course(2, "Learn DevOps", "Hyun"),
                new Course(3, "Learn Azure", "Hyun"),
                new Course(4, "Learn Python", "Leo")
                // JSON 응답이 반환된다.
        );
    }
}
