document.getElementById('recommendation-form').addEventListener('submit', function(event) {
    event.preventDefault();

    var newRecommendationText = document.getElementById('new-recommendation').value;
    if (newRecommendationText.trim() !== '') {
        var newRecommendation = document.createElement('div');
        newRecommendation.classList.add('recommendation');
        newRecommendation.innerHTML = '<p>"' + newRecommendationText + '"</p><p>- Anonymous</p>';

        document.querySelector('.recommendation-list').appendChild(newRecommendation);

        alert('New recommendation added!');
        document.getElementById('new-recommendation').value = '';
    }
});