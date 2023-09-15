
document.addEventListener("DOMContentLoaded", () => {
    document.getElementById('PasNoMatch').style.visibility = "hidden"
    document.getElementById('emtySlot').style.visibility = "hidden"
    document.getElementById('invalidPass').style.visibility = "hidden"
    document.getElementById('create').addEventListener('click', (e) => {
        const email = document.getElementById('email').value
        const first_name = document.getElementById('first_name').value
        const last_name = document.getElementById('last_name').value
        const password = document.getElementById('password').value
        const retyped_pass = document.getElementById('retyped_pass').value
        const address = document.getElementById('address').value
        const age = document.getElementById('age').value
        const name = first_name + last_name


        const token = localStorage.getItem('token');

        if (email != "" && first_name != "" && last_name != "" && password != "" && retyped_pass != "" && address != "") {
            if (retyped_pass === password) {
                const data = {
                    email, name, password, address, age
                }
                fetch("/users", {
                    method: "POST",
                    headers: {
                        "Content-Type": "application/json",
                        "Authorization": `Bearer ${token}`,
                    },
                    body: JSON.stringify(data)
                }).then(response => {
                    if (response.status === 400) { document.getElementById('invalidPass').style.visibility = "visible" }
                    else { window.open('/sign-in', "_self"); }
                }).catch()

            } else {
                document.getElementById('PasNoMatch').style.visibility = "visible"
            }
        } else {
            document.getElementById('emtySlot').style.visibility = "visible"
        }



    })
})
