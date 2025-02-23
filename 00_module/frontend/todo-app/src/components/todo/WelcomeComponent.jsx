import { useParams, Link } from "react-router-dom"

import { useState } from "react";
import { retrieveHelloWorldPathVariable } from "./api/HelloWorldApiService";

export default function WelcomeComponent() {

    const [message, setMessage] = useState(null)

    function callHelloWorldPathVariable() {
        console.log('called')
        retrieveHelloWorldPathVariable('Hyun')
            .then((response) => setMessage(response.data.message))
            .catch((error) => console.log(error))
            .finally(() => console.log('cleanup'))
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
                    onClick={callHelloWorldPathVariable}
                >
                    Call Hello World Bean Path Variable REST API
                </button>
            </div>
            <div className="text-info">
                {message}
            </div>
        </div>
    )
}

