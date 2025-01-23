package com.hyun.springboot.learn_jpa_and_hibernate.course.jdbc;

import com.hyun.springboot.learn_jpa_and_hibernate.course.Course;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository // DB 연결
public class CourseJdbcRepository {

    @Autowired
    // 외부에서 접근을 할 수 없도록 지정
    private JdbcTemplate springjdbcTemplate;

    // Query 변수 지정
    private static String INSERT_QUERY =
            """
                insert into course (id, name, author)
                values(?, ?, ?);        
            """;

    private static String DELETE_QUERY =
            """
                delete from course 
                where id = ?;
            """;

    private static String SELECT_QUERY =
            """
                select * from course
                where id = ?;
            """;

    public void insert(Course course) {
        springjdbcTemplate.update(INSERT_QUERY, course.getId(), course.getName(), course.getAuthor());
    }

    public void deleteById(long id) {
        springjdbcTemplate.update(DELETE_QUERY, id);
    }

    // Course라는 타입의 객체를 반환한다.
    public Course findById(long id) {
        return springjdbcTemplate.queryForObject(
                SELECT_QUERY,
                // ResultSet -> Bean => Row Mapper =>
                // Row Mapper는 결과 세트의 각 행을 특정 Bean에 연결해준다.
                // Course.class -> Course 클래스를 나타내는 클래스 객체, 매핑 과정에서 사용한다
                new BeanPropertyRowMapper<>(Course.class),
                id
        );
    }

    // Course라는 타입의 객체를 List에 담은 것을 반환한다.
    // db 전체 데이터를 확인하는 것
    // Course.class -> Course 클래스를 나타내는 클래스 객체, 매핑 과정에서 사용한다
    public List<Course> findAll() {
        return springjdbcTemplate.query(
                "select * from course",
                new BeanPropertyRowMapper<>(Course.class)
        );
    }
}
