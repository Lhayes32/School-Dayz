var list = []
if (document.readyState == 'loading') {
    document.addEventListener('DOMContentLoaded', ready)
} else {
    ready()
}

function ready(){
    var addToCartButtons = document.getElementsByClassName('btn-atc')
    for (var i = 0; i < addToCartButtons.length; i++) {
        var button = addToCartButtons[i]
        console.log(button)
        button.addEventListener('click', addToCartClicked)
    }

    var checkout =  document.getElementsByClassName('btn-checkout');
    for (var i = 0; i < checkout.length; i++) {
        var button = checkout[i]
        console.log(button)
        button.addEventListener('click', checkoutButtonClicked)
    }
    

    var noti = document.querySelector('.btn-checkout');
    var button = document.getElementsByClassName('btn-atc');
    for(but of button)
    {
    but.addEventListener('click', (e)=>{
        var add= Number(noti.getAttribute('data-count') || 0);
        noti.setAttribute('data-count', add + 1);
        noti.classList.add('zero');

        })
    }

}

function checkoutButtonClicked(event){
    var button = event.target;
    localStorage.setItem("list", JSON.stringify(list));
}

function addToCartClicked(event) {
    var button = event.target
    var shopItem = button.parentElement
    var title = shopItem.getElementsByClassName('name')[0].innerText
    var price = shopItem.getElementsByClassName('price')[0].innerText
    var imageSrc = shopItem.getElementsByClassName('image')[0].src
    var list_add = [title,price,imageSrc]
    
    list.push(list_add)
    console.log(list)
}




