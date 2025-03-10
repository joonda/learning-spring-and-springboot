import axios from "axios";

const apiClient = axios.create(
    {
        baseURL: 'http://localhost:8080'
    }
)
// export function retrieveHelloWorldBean () {
//     return apiClient.get('http://localhost:8080/hello-world-bean')
// }

export const retrieveHelloWorldBean = () => apiClient.get('/hello-world-bean')

export const retrieveHelloWorldPathVariable = (username) => apiClient.get(`/hello-world/path-variable/${username}`)
