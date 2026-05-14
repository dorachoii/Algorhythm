
export function frontDoorResponse(line) {
  return line[0];
}


export function frontDoorPassword(word) {

  let answer = word[0].toUpperCase();

  for (let i = 1; i < word.length; i++) {
    answer += word[i].toLowerCase();
  }
  return answer;
}


export function backDoorResponse(line) {
  let answer = line.trim();
  return answer[answer.length -1];
}


export function backDoorPassword(word) {
  word = word.trim();

  let answer = word[0].toUpperCase();

  for(let i = 1; i< word.length; i++){
    answer += word[i].toLowerCase();
  }

  return answer + ', please';
}
