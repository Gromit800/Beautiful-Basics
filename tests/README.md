# KnitProject
This software works with the studiosainterose.ca website, it implements a logic that matches the selected sizes from the user to the perfect knitting pattern for various knitting projects. The back end is coded in C++ and uses multiple json files as databases to fetch the right sizes for every type of measure and pattern selected. It is hosted on an AWS lambda server that receives requests via the custom HTML page I've added to the client's website behind a paywall.

## Usage
The user selects the wanted pattern on the website which prompts a form to be filled with various sizes. Once completed, the form (custom html page) sends a request containing a json object payload. That object is relayed to the back end via a short python script hosted on the lambda to deal with HTTP failures to return the correct status code, and to send the payload to the C++ logic. That logic creates an object for the wanted pattern with the appropriate values to be included in the final pattern. Once the values are fetched, it inserts them in an HTML string that represents the final product. That final string is then returned to the website where it is displayed to the user. The user can then choose to print another pattern, and will be able to save it locally and print it with a CSS function that I'll eventually incorporate.

## Security
In order to protect the lamba from denial of services attacks since it's using a lambda URL instead of a API gate, I keep the concurrency level at 0 when I'm not currently testing the software. It is currently in a working state, but is not available to the public yet. Many more security measure will be implemented like throttling, delaying service and whitelisting users in order to maintain a level of activity that allows this service to remain free.

## Note
Please note that some necessary files for my program to run correctly have been removed from this repository in order to protect the intelectual proprety of studiosainterose.ca's owner. This repo's use is to showcase my project only.
