package com.hyun.springboot.learn_jpa_and_hibernate.course;

import com.hyun.springboot.learn_jpa_and_hibernate.course.springdatajpa.CourseSpringDataJpaRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

@Component // 실행 시, 컴포넌트로 확인할 수 있도록 지정
public class CourseCommandLineRunner implements CommandLineRunner {

//    @Autowired
//    private CourseJdbcRepository repository;

//    @Autowired
//    private CourseJpaRepository repository;

    @Autowired
    private CourseSpringDataJpaRepository repository;

    @Override
    public void run(String... args) throws Exception {
        repository.save(new Course(1, "Learn AWS Spring Data Jpa!", "June")); // repository class안에 있는 insert class를 실행
        repository.save(new Course(2, "Learn Azure Spring Data Jpa!", "June")); // repository class안에 있는 insert class를 실행
        repository.save(new Course(3, "Learn DevOps Spring Data Jpa!", "June")); // repository class안에 있는 insert class를 실행

        repository.deleteById(1L);

        System.out.println(repository.findById(3L));

        System.out.println(repository.findAll());
        System.out.println(repository.count());

        System.out.println(repository.findByAuthor("June"));
        System.out.println(repository.findByAuthor(""));

        System.out.println(repository.findByName("Learn Azure Spring Data Jpa!"));
        System.out.println(repository.findByName(""));
    }
}
