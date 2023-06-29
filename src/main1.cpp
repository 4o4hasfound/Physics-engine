//#include <SFML/Graphics.hpp>
//#include "Math/Vector.hpp"
//#include "setup.hpp"
//#include <random>
//
//#include <iostream>
//
//#include "Debug/Print.hpp"
//#include "Audio/Audio.hpp"
//#include <SFML/Audio.hpp>
//
//
//#include <chrono>
//using namespace Pulsar;
//
//class Bird {
//public:
//	Bird(int i) : pos(0) {
//		type = rand() % 4;
//		aud = Audio(std::to_string(type+1) + ".wav", 1, true);
//		int dir = rand() % 2 ? 1 : -1;
//		switch (type) {
//		case 0:
//			speed = vec2(0.000005, 0.000005);
//			break;
//		case 05:
//			speed = vec2(0.000005, 0.000005);
//			break;
//		case 2:
//			speed = vec2(0.000005, 0.000005);
//			break;
//		case 3:
//			speed = vec2(0.000005, 0.000005);
//			break;
//		}
//		speed *= dir;
//		pos = speed * ToDecimal(-1000);
//	}
//	
//	void Update() {
//		pos += speed;
//		aud.setPosition(pos.x, 0, pos.y);
//	}
//
//	void Play() {
//		aud.play();
//	}
//private:
//	vec2 pos;
//	vec2 speed;
//	Audio aud;
//	int32_t type;
//};
//
//#include <vector>
//#include "Physics/Collider.hpp"
//#include "Physics/Object.hpp"
//#include "Physics/SphereCollider.hpp"
//#include "Math/Transform.hpp"
//#include "Physics/QuadTree.hpp"
//#include "Physics/AABB.hpp"
//
//#include <bitset>
//#include <algorithm>
//
//#include "Shape/Circle.hpp"
//#include "Math/TriangonometricFunc.hpp"
//
//struct pair_hash {
//	template <class T1, class T2>
//	std::size_t operator() (const std::pair<T1, T2>& pair) const {
//		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
//	}
//};
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
//	sf::CircleShape shape(400.f);
//	shape.setPosition(100, 100);
//	shape.setFillColor(sf::Color::White);
//	std::vector<Object> objs;
//	QuadTree qt;
//	bool rpressed = false;
//	vec2 position(500, 500);
//	Decimal radius = 400;
//	sf::Clock deltaClock;
//	srand(NULL);
//	std::vector<sf::Vertex> verts;
//	for (int i = 0; i < 10; ++i) {
//		objs.push_back(Object(new SphereCollider(5), vec2(rand() % 300 + 300, rand() % 300 + 300)));
//		sf::Vertex v;
//		v.position = sf::Vector2f(objs.back().m_position.x, objs.back().m_position.y);
//		v.color = sf::Color::Black;
//		verts.push_back(v);
//		qt.Insert(objs.size() - 1, objs.back().m_aabb);
//	}
//	window.setFramerateLimit(60);
//	Decimal averageTime = 0;
//	int averageAmount = 0;
//	Decimal updateAverage = 0;
//	int updateAmount = 0;
//	sf::Font font;
//	font.loadFromFile("consola.ttf");
//	sf::Text text;
//	text.setFont(font);
//	text.setCharacterSize(20);
//	int WidthDiv = 20;
//	int HeightDiv = 20;
//	int cellWidth = 1000 / WidthDiv;
//	int cellHeight = 1000 / HeightDiv;
//	while (window.isOpen()) {
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//			if (event.type == sf::Event::MouseButtonPressed) {
//				if (event.mouseButton.button == sf::Mouse::Right) {
//					if (!rpressed) {
//						rpressed = true;
//						objs.push_back(Object(new SphereCollider(10), vec2(event.mouseButton.x, event.mouseButton.y)));
//						qt.Insert(objs.size() - 1, objs.back().m_aabb);
//					}
//				}
//			}
//			if (event.type == sf::Event::MouseButtonReleased) {
//				if (event.mouseButton.button == sf::Mouse::Right) {
//					if (rpressed) {
//						rpressed = false;
//						objs.push_back(Object(new SphereCollider(10), vec2(event.mouseButton.x, event.mouseButton.y)));
//						qt.Insert(objs.size() - 1, objs.back().m_aabb);
//					}
//				}
//			}
//		}
//		if (rpressed) {
//			sf::Vector2i pos = sf::Mouse::getPosition(window);
//			objs.push_back(Object(new SphereCollider(rand() % 15 + 5), vec2(pos.x, pos.y)));
//			sf::Vertex v;
//			v.position = sf::Vector2f(pos.x, pos.y);
//			v.color = sf::Color::Black;
//			verts.push_back(v);
//			qt.Insert(objs.size() - 1, objs.back().m_aabb);
//		}
//		
//		window.clear();
//		window.draw(shape);
//		sf::Time dt = deltaClock.restart();
//		Decimal dtSec = dt.asSeconds();
//		int subStep = 24;
//		dtSec /= subStep;
//		Decimal collTimeTotal =	0;
//		Decimal collTimeCount =	0;
//		Decimal upTimeTotal =	0;
//		Decimal upTimeCount =	0;
//		Decimal totalChecks =	0;
//		Decimal totalIter =		0;
//		Decimal totalInsert =	0;
//		Decimal insertCount =	0;
//		AverageTime oneIter;
//		Decimal sslope = 0;
//		vec2 avg;
//		Decimal r;
//		for (int k = 0; k < subStep; ++k) {
//			for (auto& e : objs) {
//				e.Accelerate(vec2(0.0, 1000000.0) * ToDecimal(dtSec));
//			}
//			for (auto& e : objs) {
//				const vec2 toObj = e.m_position - position;
//				const Decimal dist = length(toObj);
//				if (dist > radius - e.m_collider->getRadius()) {
//					const vec2 n = toObj / dist;
//					e.m_position = position + n * ToDecimal(radius - e.m_collider->getRadius());
//				}
//			}
//			Decimal minX = DecimalMax, maxX = DecimalMin;
//			Decimal totalX = 0, totalY = 0;
//			for (auto& obj : objs) {
//				Decimal x = obj.m_aabb.getMinX(), y = obj.m_aabb.getMinY();
//				minX = std::min(minX, x);
//				maxX = std::max(maxX, x);
//				totalX += x;
//			}
//			Decimal disX = totalX / objs.size() - (minX + maxX) / 2;
//			int32_t OptType = disX > 0 ? 0 : 0;
//			std::vector<Object*> sortedObject(objs.size());
//			for (int i = 0; i < objs.size(); ++i) {
//				sortedObject[i] = &objs[i];
//			}
//			if (OptType == 0) {
//				std::sort(sortedObject.begin(), sortedObject.end(), [&](Object* a, Object* b) {
//					return a->m_aabb.getPoint(OptType) > b->m_aabb.getPoint(OptType);
//					});
//			}
//			else {
//				std::sort(sortedObject.begin(), sortedObject.end(), [&](Object* a, Object* b) {
//					return a->m_aabb.getPoint(OptType) < b->m_aabb.getPoint(OptType);
//					});
//			}
//			auto start = sortedObject.begin();
//			for (int i = 0, len = sortedObject.size(); i < len; i++) {
//				Object* obj1 = sortedObject[i];
//				if (OptType == 0) {
//					start = std::lower_bound(start, sortedObject.end(), obj1->m_aabb.getPoint(OptType), [&](Object* a, vec2 b) {
//						return b > a->m_aabb.getPoint(OptType);
//						});
//				}
//				else {
//					start = std::lower_bound(start, sortedObject.end(), obj1->m_aabb.getPoint(OptType), [&](Object* a, vec2 b) {
//						return b < a->m_aabb.getPoint(OptType);
//						});
//				}
//				++totalIter;
//				for (auto s = start, end = sortedObject.end(); s != end; ++s) {
//					if ((*s) == obj1) continue;
//					Object* obj2 = (*s);
//					//if (obj2->m_aabb.getMinX() >= obj1->m_aabb.getMaxX() && obj2->m_aabb.getMinY() >= obj1->m_aabb.getMaxY()) break;
//					//if (OptType == 3 && obj2->m_aabb.getMinX() >= obj1->m_aabb.getMaxX() && obj2->m_aabb.getMinY() >= obj1->m_aabb.getMaxY()) break;
//					//if (OptType == 0 && obj2->m_aabb.getMinY() >= obj1->m_aabb.getMaxY()) continue;
//					//if (OptType == 3 && obj1->m_aabb.getMinY() >= obj2->m_aabb.getMaxY()) continue;
//					++totalChecks;
//					CollisionPoint collidePoint = obj1->m_collider->TestCollision(obj1->m_position, obj2->m_collider, obj2->m_position);
//					if (collidePoint.hasCollide) {
//						const vec2 n = collidePoint.Normal / collidePoint.Depth;
//						obj1->m_position += ToDecimal(0.5 * collidePoint.Delta) * n;
//						obj2->m_position -= ToDecimal(0.5 * collidePoint.Delta) * n;
//					}
//				}
//			}
//			Clock collClock;
//			Decimal ux = 0, uy = 0, totX = 0, totY = 0, totXY = 0;
//			for (int i = 0; i < objs.size(); ++i) {
//				Decimal x = objs[i].m_aabb.getMinX(), y = objs[i].m_aabb.getMinY();
//				ux += x;
//				uy += y;
//			}
//			ux /= objs.size();
//			uy /= objs.size();
//			for (int i = 0; i < objs.size(); ++i) {
//				Decimal x = objs[i].m_aabb.getMinX(), y = objs[i].m_aabb.getMinY();
//				totX += (x - ux) * (x - ux) / (objs.size() - 1);
//				totY += (y - uy) * (y - uy) / (objs.size() - 1);
//				totXY += (x - ux) * (y - uy) / (objs.size() - 1);
//			}
//			totX = std::sqrtf(totX);
//			totY = std::sqrtf(totY);
//			Decimal slope = (totXY / (totX * totY));
//			Decimal angle = std::atan(slope);
//			sslope = slope;
//			avg = vec2(ux, uy);
//			r = angle;
//			angle = -PI / 4 - angle;
//			avg = rotate(avg, vec2(500, 500), angle);
//			sslope = std::tan(-PI / 4);
//			struct ObjectOriented {
//				Object* object;
//				vec2 tl;
//				vec2 br;
//			};
//			std::vector<ObjectOriented> oriented(objs.size());
//			for (int i = 0; i < objs.size(); ++i) {
//				oriented[i].object = &objs[i];
//				oriented[i].tl = rotate(objs[i].m_aabb.getTL(), vec2(500), angle);
//				oriented[i].br = rotate(objs[i].m_aabb.getBR(), vec2(500), angle);
//			}
//			std::sort(oriented.begin(), oriented.end(), [](ObjectOriented a, ObjectOriented b) {
//				return a.tl < b.tl;
//				});
//			//std::vector<Object*> tl(objs.size());
//			//for (int i = 0; i < objs.size(); ++i) {
//			//	tl[i] = &objs[i];
//			//}
//			//std::sort(tl.begin(), tl.end(), [](Object* a, Object* b) {
//			//	return a->m_aabb.getTL() < b->m_aabb.getTL();
//			//	});
//			for (int i = 0, len = oriented.size(); i < len; i++) {
//				Object* obj1 = oriented[i].object;
//				++totalIter;
//				for (int j = i + 1; j < oriented.size(); j++) {
//					Object* obj2 = oriented[j].object;
//					if (oriented[j].tl.x >= oriented[i].br.x && oriented[j].tl.y >= oriented[i].br.y) break;
//					if (oriented[j].tl.y >= oriented[i].br.y) continue;
//					++totalChecks;
//					CollisionPoint collidePoint = obj1->m_collider->TestCollision(obj1->m_position, obj2->m_collider, obj2->m_position);
//					if (collidePoint.hasCollide) {
//						const vec2 n = collidePoint.Normal / collidePoint.Depth;
//						obj1->m_position += ToDecimal(0.5 * collidePoint.Delta) * n;
//						obj2->m_position -= ToDecimal(0.5 * collidePoint.Delta) * n;
//					}
//				}
//			}
//			std::vector<Object*> tl(objs.size());
//			for (int i = 0; i < objs.size(); ++i) {
//				tl[i] = &objs[i];
//			}
//			std::sort(tl.begin(), tl.end(), [](Object* a, Object* b) {
//				return a->m_aabb.getTL() < b->m_aabb.getTL();
//				});
//			for (int i = 0, len = tl.size(); i < len; i++) {
//				Object* obj1 = tl[i];
//				++totalIter;
//				for (int j = i + 1; j < tl.size(); ++j) {
//					Object* obj2 = tl[j];
//					if (obj2 == obj1) continue;
//					if (obj2->m_aabb.getMinX() >= obj1->m_aabb.getMaxX() && obj2->m_aabb.getMinY() >= obj1->m_aabb.getMaxY()) break;
//					if (obj2->m_aabb.getMinY() >= obj1->m_aabb.getMaxY()) continue;
//					++totalChecks;
//					CollisionPoint collidePoint = obj1->m_collider->TestCollision(obj1->m_position, obj2->m_collider, obj2->m_position);
//					if (collidePoint.hasCollide) {
//						obj1->m_position += ToDecimal(0.5 * collidePoint.Delta) * collidePoint.Normal;
//						obj2->m_position -= ToDecimal(0.5 * collidePoint.Delta) * collidePoint.Normal;
//					}
//				}
//			}
//			/*auto run = [&]() {
//				std::vector<Object*> tl(objs.size());
//				for (int i = 0; i < objs.size(); ++i) {
//					tl[i] = &objs[i];
//				}
//				std::sort(tl.begin(), tl.end(), [](Object* a, Object* b) {
//					return a->m_aabb.getTL() < b->m_aabb.getTL();
//					});
//				auto start = tl.begin();
//				for (int i = 0, len = tl.size(); i < len; i++) {
//					Object* obj1 = tl[i];
//					start = std::lower_bound(start, tl.end(), obj1->m_aabb.getTL(), [](Object* a, vec2 b) {
//						return a->m_aabb.getTL() < b;
//						});
//					++totalIter;
//					for (auto s = start, end = tl.end(); s != end; ++s) {
//						if ((*s) == obj1) continue;
//						Object* obj2 = (*s);
//						if (obj2->m_aabb.getMinX() >= obj1->m_aabb.getMaxX() && obj2->m_aabb.getMinY() >= obj1->m_aabb.getMaxY()) break;
//						if (obj2->m_aabb.getMinY() >= obj1->m_aabb.getMaxY()) continue;
//						++totalChecks;
//						CollisionPoint collidePoint = obj1->m_collider->TestCollision(obj1->m_position, obj2->m_collider, obj2->m_position);
//						if (collidePoint.hasCollide) {
//							const vec2 n = collidePoint.Normal / collidePoint.Depth;
//							obj1->m_position += ToDecimal(0.5 * collidePoint.Delta) * n;
//							obj2->m_position -= ToDecimal(0.5 * collidePoint.Delta) * n;
//						}
//					}
//				}
//			};*/
//
//			auto result = collClock.End();
//			collTimeTotal += result.asSec;
//			++collTimeCount;
//			std::unordered_map<int32_t, bool> visited;
//			auto leaves = qt.GetLeaves();
//			for (auto& leaf : leaves) {
//				for (auto& id : leaf->eltNode) {
//					if (!visited[id]) {
//						visited[id] = true;
//						int32_t _id = qt.getInd(id);
//						std::vector<int32_t> indexes = qt.Query(objs[_id].m_aabb);
//						for (auto& ind : indexes) {
//							if (ind == _id) continue;
//							Object& obj2 = objs[ind];
//							CollisionPoint collidePoint = objs[_id].m_collider->TestCollision(objs[_id].m_position, obj2.m_collider, obj2.m_position);
//							if (collidePoint.hasCollide) {
//								const vec2 n = collidePoint.Normal / collidePoint.Depth;
//								objs[_id].m_position += ToDecimal(0.5 * collidePoint.Delta) * n;
//								obj2.m_position -= ToDecimal(0.5 * collidePoint.Delta) * n;
//							}
//						}
//					}
//				}
//			}
//			auto update = [&]() {
//				for (int i = 0, len = objs.size(); i < len; ++i) {
//					objs[i].Update(dtSec);
//					verts[i].position = sf::Vector2f(objs[i].m_position.x, objs[i].m_position.y);
//				}
//			};
//			auto resUpdate = Time<void>(update);
//			upTimeTotal += resUpdate.asSec;
//			++upTimeCount;
//			for (int i = 0, len = objs.size(); i < len; ++i) {
//				qt.Update(i, objs[i].m_aabb);
//			}
//			updateAverage += updateTime;
//			++updateAmount;
//			print("Average update time: ", updateAverage / updateAmount);
//			
//		}
//		text.setString("Check collistion time: " + std::to_string(collTimeTotal / collTimeCount));
//		text.setPosition(50, 0);
//		window.draw(text);
//		text.setString("Update grid time: " + std::to_string(totalInsert / insertCount));
//		text.setPosition(50, 30);
//		window.draw(text);
//		text.setString("r: " + std::to_string(0));
//		text.setPosition(50, 90);
//		window.draw(text);
//		text.setString("Average collision checkes per object: " + std::to_string(totalChecks / totalIter));
//		text.setPosition(50, 60);
//		window.draw(text);
//		sf::Vertex line[2];
//		line[0].position = sf::Vector2f(avg.x - 100, avg.y - 100 * sslope);
//		line[0].color = sf::Color::Yellow;
//		line[1].position = sf::Vector2f(avg.x + 400, avg.y + 400 * sslope);
//		line[1].color = sf::Color::Red;
//		window.draw(&line[0], 2, sf::Lines);
//		auto resDraw = Time<void>([&]() {
//			sf::CircleShape c;
//			c.setFillColor(sf::Color::Black);
//			for (auto& e : objs) {
//				c.setRadius(e.m_collider->getRadius());
//				c.setPosition(e.m_position.x - e.m_collider->getRadius(), e.m_position.y - e.m_collider->getRadius());
//				window.draw(c);
//			}
//			});
//		Decimal ux = 0, uy = 0, totX = 0, totY = 0, totXY = 0;
//		for (int i = 0; i < objs.size(); ++i) {
//			Decimal x = objs[i].m_aabb.getMinX(), y = objs[i].m_aabb.getMinY();
//			ux += x;
//			uy += y;
//		}
//		/*ux /= objs.size();
//		uy /= objs.size();
//		for (int i = 0; i < objs.size(); ++i) {
//			Decimal x = objs[i].m_aabb.getMinX(), y = objs[i].m_aabb.getMinY();
//			totX += (x - ux) * (x - ux) / (objs.size() - 1);
//			totY += (y - uy) * (y - uy) / (objs.size() - 1);
//			totXY += (x - ux) * (y - uy) / (objs.size() - 1);
//		}
//		totX = std::sqrtf(totX);
//		totY = std::sqrtf(totY);
//		Decimal slope = (totXY / (totX * totY));
//		Decimal angle = PI / 2 - std::atan(slope);
//		sslope = slope;
//		avg = vec2(ux, uy);
//		r = angle;
//		avg = rotate(avg, vec2(500, 500), angle);
//		struct ObjectOriented {
//			Object* object;
//			vec2 tl;
//			vec2 br;
//		};
//		std::vector<ObjectOriented> oriented(objs.size());
//		for (int i = 0; i < objs.size(); ++i) {
//			oriented[i].object = &objs[i];
//			oriented[i].tl = rotate(objs[i].m_aabb.getTL(), vec2(500), angle);
//			oriented[i].br = rotate(objs[i].m_aabb.getBR(), vec2(500), angle);
//		}
//		ux = 0, uy = 0, totX = 0, totY = 0, totXY = 0;
//		for (int i = 0; i < oriented.size(); ++i) {
//			Decimal x = oriented[i].tl.x, y = oriented[i].tl.y;
//			ux += x;
//			uy += y;
//		}
//		ux /= objs.size();
//		uy /= objs.size();
//		for (int i = 0; i < oriented.size(); ++i) {
//			Decimal x = oriented[i].tl.x, y = oriented[i].tl.y;
//			totX += (x - ux) * (x - ux) / (oriented.size() - 1);
//			totY += (y - uy) * (y - uy) / (oriented.size() - 1);
//			totXY += (x - ux) * (y - uy) / (oriented.size() - 1);
//		}
//		totX = std::sqrtf(totX);
//		totY = std::sqrtf(totY);
//		slope = (totXY / (totX * totY));
//		print(degrees(std::tanh(slope)));
//		angle = -PI / 4;
//		sslope = std::tan(angle);
//		print(angle);
//		line[0].position = sf::Vector2f(avg.x - 100, avg.y - 100 * sslope);
//		line[0].color = sf::Color::Black;
//		line[1].position = sf::Vector2f(avg.x + 400, avg.y + 400 * sslope);
//		line[1].color = sf::Color::Red;
//		window.draw(&line[0], 2, sf::Lines);
//		for (int i = 0; i < oriented.size(); ++i) {
//			sf::CircleShape c;
//			c.setRadius(oriented[i].object->m_collider->getRadius());
//			c.setPosition(oriented[i].tl.x, oriented[i].tl.y);
//			c.setFillColor(sf::Color::Cyan);
//	 		window.draw(c);
//		}*/
//		auto resDraw = Time<void>([&]() { window.draw(&verts[0], verts.size(), sf::Points); });
//		text.setString("Draw time: " + std::to_string(resDraw.asSec));
//		text.setPosition(50, 120);
//		window.draw(text);
//		qt.DebugDraw(window);
//		qt.Cleanup();
//		window.setTitle(std::to_string(objs.size()) + ": " + std::to_string(1.0 / (dtSec * subStep)));
//		window.display();
//	}
//
//	return 0;
//}