In this project I built a console-based weather application that fetches data from an API and displays weather information 
for a given location in C to be run in Ubuntu 20.04 and uses the Betty code style.

Building a console-based weather application in C involves making HTTP requests to weather API and parsing the JSON response to display relevant information.

For simplicity, I'll use the OpenWeatherMap API for this project. I signed up for a free API key from OpenWeatherMap.

Firstly, l needed to install the libcurl library to make HTTP requests. In Ubuntu 20.04, using the code below;

sudo apt-get update
sudo apt-get install libcurl4-openssl-dev

Challenges

I had challenges with the Betty linter approving the Betty code styling which I am working on the errors found.
I had some indentation errors which is being fixed
API generation was seamless however, i hit a snag with the url which is currently resolved with some meticulous research
I had a compilation challenge because of URL definition issues. 
An https url contains several characters that makes shell sees it as a character for expansion which tends to impede the exact meaning of the url string. 


Collaboration/Communication

Before I jumped on this final project, I had a discussion with a peer about a list of projects I would like to try my hands on. 
However he indicated that I had powerful ideas but because of the limited time to execute the project, task I should focus on something lighter such as building 
with a few features and then add more afterwards. I was happy and took his advice in whole. 
Additionally he was excited about the task at hand. He said “For sure, I feel like I'll only start calling myself a software developer after putting some products out there”. 


Project Updates

My code is in the testing phase. I want to make sure I am able to display the weather for my city and then invite my peers to try it out for their cities as well. 
Furthermore I will push my code into my github account.
I successfully ran my Betty linter after correcting a few indentations regarding my loops.

