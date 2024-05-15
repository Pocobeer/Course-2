function sendRequest(method, url, body = null) {
    return new Promise((resolve, reject) => {
        const xhr = new XMLHttpRequest();
        xhr.open(method, url);
        xhr.responseType = 'json';

        xhr.onload = () => {
            if (xhr.status >= 400) {
                reject(xhr.response);
            } else {
                resolve(xhr.response);
            }
        };

        xhr.onerror = () => {
            reject(xhr.response);
        };

        if (method === 'GET') {
            xhr.send();
        } else {
            xhr.setRequestHeader('Content-Type', 'application/json');
            xhr.send(JSON.stringify(body));
        }
    });
}

const api_url = 'https://localhost:7034/api/User/Register';

// Пример использования функции для отправки GET-запроса
sendRequest('GET', api_url)
    .then(data => console.log(data))
    .catch(err => console.log(err));

// Пример использования функции для отправки POST-запроса
// sendRequest('POST', api_url, { name: 'Alex', email: 'alex@ya.ru' })
//     .then(data => console.log(data))
//     .catch(err => console.log(err));
