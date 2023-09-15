document.addEventListener("DOMContentLoaded", () => {
    const logoutA = document.getElementById("sign-out")
    logoutA.addEventListener("click", async () => {
        fetch("/logout", {
            method: "POST"
        }).then((res) => {
            window.location.href = "/sign-in"
        })
    })
})