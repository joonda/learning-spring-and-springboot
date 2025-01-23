package com.hyun.springboot.learn_jpa_and_hibernate.course.springdatajpa;

import com.hyun.springboot.learn_jpa_and_hibernate.course.Course;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

// Spring Data JPA를 이용할 때는 인터페이스를 활용한다.
// JpaRepository를 상속받아야 한다.
// <> 어떤 엔터티를 관리할지와, Id Field 넣어줌.
// Id 필드는 Course 클래스에 보면 @Id Annotation이 존재하는 것을 알 수 있다 해당 타입을 넣어준다.
public interface CourseSpringDataJpaRepository extends JpaRepository<Course, Long> {
    List<Course> findByAuthor(String author);
    List<Course> findByName(String name);
}
