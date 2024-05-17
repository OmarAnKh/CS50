document.addEventListener("DOMContentLoaded", () => {
    document.querySelector('#sign-in').addEventListener('click', async () => {
        const email = document.getElementById('email').value;
        const password = document.getElementById('password').value;
        const data = { email, password };

        try {
            const response = await fetch('/users/login', {
                method: "POST",
                headers: {
                    "Content-Type": "application/json",
                    'Accept': "*/*"
                },
                body: JSON.stringify(data)
            });

            if (response.status === 400) {
                document.getElementById('invalidSignIn').style.visibility = "visible";
                return;
            }

            if (response.ok) {
                const data2 = await response.json();
                const token = data2.token;
                const userName = data2.user.name;

                document.cookie = "token=" + token + ";";
                document.cookie = "user=" + userName + ";";
                document.cookie = "email=" + data2.user.email + ";";
                document.cookie = "age=" + data2.user.age + ";";
                document.cookie = "address=" + data2.user.address + ";";

                const anotherResponse = await fetch('/some/other/endpoint', {
                    method: "GET",
                    headers: {
                        "Content-Type": "application/json",
                        "Authorization": `Bearer ${token}`,
                        'Accept': "*/*"
                    },
                });


                fetch('', {
                    method: "GET",
                    headers: {
                        "Content-Type": "application/json",
                        "Authorization": `Bearer ${token}`
                    },
                }).then(response => {
                    if (response.ok) {
                        window.location.href = '/'
                    }
                });
            } else {
                console.error('An error occurred during sign-in.');
            }
        } catch (error) {
            console.error('An error occurred:', error);
        }
    });
});




