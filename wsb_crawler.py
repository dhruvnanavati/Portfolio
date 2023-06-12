import praw
import pandas as pd
import requests
from textblob import TextBlob
import plotly.express as px

def get_sentiment(text):
    blob = TextBlob(text)
    sentiment = blob.sentiment.polarity
    return sentiment


def get_posts(subreddit, limit):
    posts = []
    for post in subreddit.hot(limit=limit):
        posts.append([post.title, post.score, post.id, post.subreddit, post.url, post.num_comments, post.selftext, post.created])
    return pd.DataFrame(posts, columns=['title', 'score', 'id', 'subreddit', 'url', 'num_comments', 'body', 'created'])


url = "https://www.sec.gov/files/company_tickers.json"
response = requests.get(url)

data = response.json()
tickers = [info['ticker'] for info in data.values()]
companies = {info['ticker']: info['title'] for info in data.values()}


reddit = praw.Reddit(client_id='WDcVd1FovMjIZAFg4hh6Hw',
                     client_secret='zHOt2KpqfUo_BwbCJwesz8Wn_X0MVw',
                     user_agent='sentiments')

subreddit = reddit.subreddit('wallstreetbets')
posts = get_posts(subreddit, 1000)

posts['sentiment'] = posts['body'].apply(get_sentiment)

sentiments = {ticker: [] for ticker in tickers}
for ticker in tickers:
    relevant_posts = posts[posts['body'].str.contains(ticker)]
    sentiments[ticker] = list(relevant_posts['sentiment'])

sentiments_df = pd.DataFrame(list(sentiments.items()), columns=['Ticker', 'SentimentList'])

sentiments_df['NumPosts'] = sentiments_df['SentimentList'].apply(len)
sentiments_df = sentiments_df[sentiments_df['NumPosts'] >= 5]

sentiments_df['Sentiment'] = sentiments_df['SentimentList'].apply(lambda x: sum(x) / len(x))

sentiments_df = sentiments_df.sort_values('Sentiment')

fig = px.bar(sentiments_df, x='Ticker', y='Sentiment', 
             title='Sentiment Analysis of Stocks on r/wallstreetbets',
             labels={'Sentiment': 'Sentiment', 'Ticker': 'Stock'},
             hover_data=['Ticker'])

fig.show()