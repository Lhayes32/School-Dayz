
import flask
from flask import jsonify, request
import polynomials
import poly_algebra

app = flask.Flask(__name__)


# /evaluate handler can go here
@app.route("/evaluate")
def evaluate():
    try:
        parameters = request.get_json()
        # Uncomment this next line to see what the server is actually getting with parameters
        # print("parameters", parameters)

        # get the data needed out of the parameters dictionary
        val = polynomials.evaluate(parameters['x'], parameters['poly'])

        # Convert the data to json and reply
        return jsonify(val)
    except KeyError as ke:
        #  short message with status 500
        #  KeyError exceptions don't provide a very helpful message
        return "Parameter missing: " + str(ke), 500
    except Exception as ex:
        # Other exceptions seem to provide sufficient messages
        #  The messages may be confusing, but we'll just send them to the client
        return str(ex), 500


@app.route("/bisection")
def bisection():
    try:
        parameters = request.get_json()
        # Uncomment this next line to see what the server is actually getting with parameters
        # print("parameters", parameters)

        # get the data needed out of the parameters dictionary
        val = polynomials.bisection(parameters['a'], parameters['b'], parameters['poly'], parameters['tolerance'])

        # Convert the data to json and reply
        return jsonify(val)
    except KeyError as ke:
        #  short message with status 500
        #  KeyError exceptions don't provide a very helpful message
        return "Parameter missing: " + str(ke), 500
    except Exception as ex:
        # Other exceptions seem to provide sufficient messages
        #  The messages may be confusing, but we'll just send them to the client
        return str(ex), 500


@app.route("/from_roots")
def from_roots():
    try:
        parameters = request.get_json()
        # Uncomment this next line to see what the server is actually getting with parameters
        # print("parameters", parameters)

        # get the data needed out of the parameters dictionary
        val = poly_algebra.poly_from_roots(parameters['roots'])

        # Convert the data to json and reply
        return jsonify(val)
    except KeyError as ke:
        #  short message with status 500
        #  KeyError exceptions don't provide a very helpful message
        return "Parameter missing: " + str(ke), 500
    except Exception as ex:
        # Other exceptions seem to provide sufficient messages
        #  The messages may be confusing, but we'll just send them to the client
        return str(ex), 500

if __name__ == "__main__":
    app.run(debug=True, use_reloader=True)
