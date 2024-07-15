// Smooth scroll to sections
function scrollToSection(sectionId) {
    document.getElementById(sectionId).scrollIntoView({ behavior: 'smooth' });
}

// Form submission handler
document.getElementById('contactForm').addEventListener('submit', function(event) {
    event.preventDefault();
    alert('Thank you for your message!');
    this.reset();
});
