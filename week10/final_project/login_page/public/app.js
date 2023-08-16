document.addEventListener("DOMContentLoaded", function () {
    let email = document.getElementById("email");
    let pass = document.getElementById("password");
    let re_pass = document.getElementById("retyped_pass");
    let first_name = document.getElementById("first_name");
    let last_name = document.getElementById("last_name");
    let Address = document.getElementById("address");
    const baseUrl = '../server.js';

    document.getElementById('create').addEventListener('click', async function () {

        const res = await fetch(baseUrl, console.log(10), {

            method: 'POST',
            headers: {
                "Content-Type": 'application/json'
            },
            body: JSON.stringify({
                email: email.value,
                password: pass.value,
                retyped_pass: re_pass.value,
                first_name: first_name.value,
                last_name: last_name.value,
                address: Address.value
            })
            
        });
        
    });
});