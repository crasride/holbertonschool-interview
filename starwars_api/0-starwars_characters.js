#!/usr/bin/node
const request = require('request');

/* Check if the Movie_ID is provided as a command line argument */
if (process.argv.length !== 3) {
  console.error('Usage: ./0-starwars_characters.js <Movie_ID>');
  process.exit(1);
}

/* Get the Movie_ID from the command line arguments */
const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

/* Recursive function to process characters sequentially */
function characterLoop (characters, index) {
  /* If all characters have been processed, exit the function */
  if (index === characters.length) {
    return;
  }

  /* Get the URL of the current character */
  const characterUrl = characters[index];

  /* Make a request to fetch character details */
  request(characterUrl, (charError, charResponse, charBody) => {
    if (charError) {
      console.error('Error fetching character:', charError);
      process.exit(1);
    }

    if (charResponse.statusCode !== 200) {
      console.error('Invalid response for character:', charResponse.statusCode);
      process.exit(1);
    }

    /* Parse the response and display the character's name */
    const character = JSON.parse(charBody);
    console.log(character.name);

    /* Process the next character in the sequence recursively */
    characterLoop(characters, index + 1);
  });
}

/* Make a request to fetch film details */
request(url, (error, response, body) => {
  if (error) {
    console.error('Error:', error);
    process.exit(1);
  }

  if (response.statusCode !== 200) {
    console.error('Invalid response:', response.statusCode);
    process.exit(1);
  }

  // Parse the response and get the list of characters
  const film = JSON.parse(body);
  const characters = film.characters;

  // Start processing characters sequentially
  characterLoop(characters, 0);
});
