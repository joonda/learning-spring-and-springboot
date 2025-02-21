import { useParams, Link } from "react-router-dom"
import axios from "axios";

export default function WelcomeComponent() {

    function callHelloWorldRestApi() {
        console.log('called')
        axios.get('http://localhost:8080/hello-world-bean')
            .then((response) => successfulResponse(response))
            .catch((error) => errorResponse(error))
            .finally(() => console.log('cleanup'))
    }

    function successfulResponse(response) {
        console.log(response)
    }

    function errorResponse(error) {
        console.log(error)
    }

    const param = useParams()
    return (
        <div className="Welcome">
            <h1>Welcome to {param.username}</h1>
            <div>
                Manage Your todos - <Link to='/todos'>Go here</Link>
            </div>
            <div>
                <button className="btn btn-success m-5"
                    onClick={callHelloWorldRestApi}
                >
                    Call Hello World REST API
                </button>
            </div>
        </div>
    )
}

