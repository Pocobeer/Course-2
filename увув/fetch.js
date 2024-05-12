const api_url = 'https://jsonplaceholder.typicode.com/users';
function sendRequest(method, url, body = null) {
    const headers = {
        'Content-Type': 'application/json'
    }
    return fetch(url, {
        method: method,
        body: JSON.stringify(body),
        headers: headers
    }).then(response => {
        if (response.ok) {
            return response.json();
        }
        return response.json().then(err => {
            const error = new Error('Что-то пошло не так');
            error.data = err;
            throw error;
        })
    })
}
// sendRequest('GET', api_url).
// then(data => console.log(data)).
// catch(err => console.log(err));
sendRequest('POST', api_url, { name: 'Alex' , email: 'alex@ya.ru'}).
then(data => console.log(data)).
catch(err => console.log(err));