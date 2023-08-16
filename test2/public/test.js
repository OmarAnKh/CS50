document.addEventListener("DOMContentLoaded", function () {
    const getinput = document.getElementById('input');
    const getBtn = document.getElementById('button');
    const baseUrl = 'http://localhost:3000/';

    getBtn.addEventListener('click', async function getinfo(e) {
        const res = await fetch(baseUrl,
            {
                method: 'POST',
                headers: {
                    "Content-Type": 'application/json'
                },
                body: JSON.stringify({
                    name: input.value
                })
            })
    });
})
