const api_url = 'https://jsonplaceholder.typicode.com/users';
function sendRequest(method, url, body = null) {
    return new Promise((resolve, reject) => {
        const xhr = new XMLHttpRequest();
        xhr.open(method, url);
        xhr.responseType = 'json';
        xhr.setRequestHeader('Content-Type', 'application/json');
        xhr.onload = () => {
            if(xhr.status >= 400) {
                reject(xhr.response);
            } else {
                resolve(xhr.response);
            }
        }
        xhr.onerror = () => {
            reject(xhr.response);
        }
        xhr.send(JSON.stringify(body));
    });
}
// sendRequest('GET', api_url).
// then(data => console.log(data)).
// catch(err => console.log(err));
sendRequest('POST', api_url, { name: 'Alex' , email: 'alex@ya.ru'}).
then(data => console.log(data)).
catch(err => console.log(err));