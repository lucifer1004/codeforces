function generateSnippet(prefix, code, description) {
  const body = code.split('\n');
  return JSON.stringify({
    prefix,
    body,
    description,
  })
}