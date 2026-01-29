import json
import subprocess

def lambda_handler(event, context):
    # 1. Prepare the Data
    # We grab the query parameters (e.g. ?size=L&gauge=22)
    # If your data comes from a POST body, use json.loads(event['body']) instead
    input_data = json.loads(event['body'])
    
    # Defaults (safety check)
    if input_data is None: input_data = {}

    # 2. Convert to String
    # We turn the dictionary back into a JSON string: '{"size": "L", "gauge": "22"}'
    json_arg = json.dumps(input_data)
    
    # 3. Call C++
    # Command: ./knit_binary '{"size": "L", ...}'
    executable = './knit'
    
    try:
        # We pass the JSON string as the ONE argument
        result_bytes = subprocess.check_output(
            [executable, json_arg], 
            stderr=subprocess.STDOUT
        )
        
        return {
            "statusCode": 200,
            "headers": { "Content-Type": "text/html" },
            "body": result_bytes.decode('utf-8')
        }

    except subprocess.CalledProcessError as e:
        return {
            "statusCode": 500,
            "body": f"C++ Error: {e.output.decode('utf-8')}"
        }
